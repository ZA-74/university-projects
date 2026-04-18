# Smart File Organizer

A smart file organization tool with Arabic web interface.

## Features

- Modern and responsive user interface
- Automatic file organization by extension
- Detailed statistics display
- Safe error handling
- Full Arabic language support

## System Requirements

- OS: Windows 10 or later
- Node.js (version 14 or later)
- Modern web browser
- Access permissions to target folders

## Installation & Setup

### Installation

```bash
npm install
```

### Running

```bash
npm start
```

The server will run on `http://localhost:3000`

## Usage

### Web Interface

1. Open browser and go to `http://localhost:3000`
2. Enter the folder path to organize
3. Click "Organize Files Now"
4. Monitor progress and view results

### Command Line

```bash
smartfileorganize.exe <folder_path>
```

## File Categories

| Category | Extensions |
|----------|------------|
| Documents | .pdf, .docx |
| Images | .jpg, .png |
| Programming | .cpp, .py |
| Others | Other files |

## Technical Notes

- The program creates folders automatically as needed
- Files are moved, not copied
- No original files are deleted
- Supports both relative and absolute paths

## Troubleshooting

### Common Issues

**Path Error:**
- Ensure the entered path is correct
- Verify the folder exists
- Check access permissions

**Runtime Issues:**
- Ensure Node.js is installed
- Run command from correct directory
- Check if port 3000 is available

## Version & Updates

Current Version: 2.0
Last Updated: April 2026

## Technologies Used

- Frontend: HTML5, CSS3, JavaScript
- Backend: Node.js with Express
- Core: C++ with Windows API

## License

This project is licensed under the MIT License.
