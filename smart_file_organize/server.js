const express = require('express');
const cors = require('cors');
const { exec } = require('child_process');
const path = require('path');

const app = express();
const PORT = 3000;

// Middleware
app.use(cors());
app.use(express.json());
app.use(express.static(path.join(__dirname)));

// Serve index.html as default
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});

// API endpoint to organize files
app.post('/api/organize', (req, res) => {
    const { path: folderPath } = req.body;

    if (!folderPath) {
        return res.status(400).json({
            success: false,
            message: 'Path is required'
        });
    }

    // Path to the executable
    const exePath = path.join(__dirname, 'output', 'smartfileorganize.exe');

    // Run the C++ executable
    exec(`"${exePath}" "${folderPath}"`, { encoding: 'utf8' }, (error, stdout, stderr) => {
        if (error) {
            console.error('Error executing program:', error);
            return res.status(500).json({
                success: false,
                message: 'Failed to organize files',
                error: error.message
            });
        }

        // Parse the output to extract statistics
        const output = stdout + stderr;
        console.log('Program output:', output);

        // Simple parsing - you might need to adjust based on actual output
        const movedMatch = output.match(/Moved:\s*(\w+)/g);
        const movedCount = movedMatch ? movedMatch.length : 0;

        // Count files by category (this is approximate)
        const documents = (output.match(/Documents/g) || []).length;
        const images = (output.match(/Images/g) || []).length;
        const programming = (output.match(/Programming/g) || []).length;
        const others = (output.match(/Others/g) || []).length;

        const foldersCount = [documents, images, programming, others].filter(count => count > 0).length;

        res.json({
            success: true,
            path: folderPath,
            movedCount: movedCount,
            documents: documents,
            images: images,
            programming: programming,
            others: others,
            foldersCount: foldersCount,
            rawOutput: output
        });
    });
});

app.listen(PORT, () => {
    console.log(`Server running at http://localhost:${PORT}`);
    console.log('Open your browser and go to http://localhost:3000');
});