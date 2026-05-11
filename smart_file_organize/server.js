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
    const { path: folderPath, options = {} } = req.body;

    if (!folderPath) {
        return res.status(400).json({
            success: false,
            message: 'Path is required'
        });
    }

    // Path to the executable
    const exePath = path.join(__dirname, 'output', 'smartfileorganize.exe');
    
    // Build command arguments based on options
    let args = [folderPath];
    
    if (options.mode === 'size') {
        args.push('--mode=size');
        if (options.minSize) args.push(`--min-size=${options.minSize}`);
        if (options.maxSize) args.push(`--max-size=${options.maxSize}`);
    } else if (options.mode === 'date') {
        args.push('--mode=date');
        if (options.dateFrom) args.push(`--date-from=${options.dateFrom}`);
        if (options.dateTo) args.push(`--date-to=${options.dateTo}`);
    } else if (options.mode === 'custom' && options.customRules) {
        args.push('--mode=custom');
        options.customRules.forEach(rule => {
            args.push(`--rule=${rule.extension}:${rule.folder}`);
        });
    }
    
    if (options.createBackup) args.push('--backup');
    if (options.duplicateCheck) args.push('--check-duplicates');
    if (options.previewMode) args.push('--preview');

    // Run the C++ executable
    exec(`"${exePath}" ${args.join(' ')}`, { encoding: 'utf8' }, (error, stdout, stderr) => {
        if (error) {
            console.error('Error executing program:', error);
            return res.status(500).json({
                success: false,
                message: 'Failed to analyze files',
                error: error.message
            });
        }

        const output = stdout + stderr;
        console.log('Program output:', output);

        if (options.previewMode) {
            // Parse preview from output
            const preview = parsePreview(output);
            res.json({
                success: true,
                preview: preview,
                path: folderPath
            });
        } else {
            // Parse the output to extract statistics
            const movedMatch = output.match(/Moved:\s*(\w+)/g);
            const movedCount = movedMatch ? movedMatch.length : 0;

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
        }
    });
});

// API endpoint to execute organization
app.post('/api/organize-execute', (req, res) => {
    const { path: folderPath, options = {} } = req.body;

    if (!folderPath) {
        return res.status(400).json({
            success: false,
            message: 'Path is required'
        });
    }

    // Path to the executable
    const exePath = path.join(__dirname, 'output', 'smartfileorganize.exe');
    
    // Build command arguments (same as above but without --preview)
    let args = [folderPath];
    
    if (options.mode === 'size') {
        args.push('--mode=size');
        if (options.minSize) args.push(`--min-size=${options.minSize}`);
        if (options.maxSize) args.push(`--max-size=${options.maxSize}`);
    } else if (options.mode === 'date') {
        args.push('--mode=date');
        if (options.dateFrom) args.push(`--date-from=${options.dateFrom}`);
        if (options.dateTo) args.push(`--date-to=${options.dateTo}`);
    } else if (options.mode === 'custom' && options.customRules) {
        args.push('--mode=custom');
        options.customRules.forEach(rule => {
            args.push(`--rule=${rule.extension}:${rule.folder}`);
        });
    }
    
    if (options.createBackup) args.push('--backup');
    if (options.duplicateCheck) args.push('--check-duplicates');
    // Note: NOT adding --preview flag for execution

    // Run the C++ executable
    exec(`"${exePath}" ${args.join(' ')}`, { encoding: 'utf8' }, (error, stdout, stderr) => {
        if (error) {
            console.error('Error executing program:', error);
            return res.status(500).json({
                success: false,
                message: 'Failed to organize files',
                error: error.message
            });
        }

        const output = stdout + stderr;
        console.log('Program output:', output);

        // Parse the output to extract statistics
        const movedMatch = output.match(/Moved:\s*(\w+)/g);
        const movedCount = movedMatch ? movedMatch.length : 0;

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

// Helper function to parse preview output
function parsePreview(output) {
    const lines = output.split('\n');
    const preview = [];
    
    lines.forEach(line => {
        // Look for lines that indicate file operations
        const match = line.match(/^(.+)\s+→\s+(.+)$/);
        if (match) {
            preview.push({
                file: match[1].trim(),
                action: match[2].trim()
            });
        }
    });
    
    return preview;
}

app.listen(PORT, '0.0.0.0', () => {
    console.log(`Server running at http://0.0.0.0:${PORT}`);
    console.log('Open your browser and go to http://localhost:3000');
    console.log('Or access from other devices: http://YOUR_IP:3000');
});