#ifndef _NAVIGATE_FOLDER_
#define _NAVIGATE_FOLDER_
#endif /*_NAVIGATE_FOLDER_*/

/*
    Folder Navigation Commands Comparison (CMD vs. Bash)
    ----------------------------------------------------
    
    | Command        | CMD (Windows)         | Bash (Linux/macOS)    |
    |---------------|----------------------|----------------------|
    | Move Forward  | cd folder_name        | cd folder_name      |
    | Move Backward | cd ..                 | cd ..               |
    | Move to Path  | cd C:\Path\To\Folder  | cd /path/to/folder  |
    | Move to Home  | N/A (No shortcut)     | cd ~                |
    | Move to Root  | cd /                  | cd /                |
    | Previous Dir  | N/A                   | cd -                |

*/

/*
    Navigation & File Viewing Commands Comparison (CMD vs. Bash)
    ------------------------------------------------------------
    
    _____________________________________________________________________________________________________________________
    |               |                       |                            |                                              |
    | Command       | CMD (Windows)         | Bash (Linux/macOS)         | Description                                  |
    |_______________|_______________________|____________________________|______________________________________________|
    | dir           | dir                   | ls                         | Lists files and folders in current directory.|
    | tree          | tree                  | tree (may require install) | Shows directory structure in tree format.    |
    |---------------|-----------------------|----------------------------|----------------------------------------------|
    | cd forward    | cd folder_name        | cd folder_name             | Moves into the specified folder.             |
    | cd backward   | cd ..                 | cd ..                      | Moves up one level in folder hierarchy.      |
    |---------------|-----------------------|----------------------------|----------------------------------------------|
    | Move to Path  | cd C:\Path\To\Folder  | cd /path/to/folder         | Moves to path.                               |
    |---------------|-----------------------|----------------------------|----------------------------------------------|
    | cd root       | cd /                  | cd /                       | Moves to the root directory.                 |
    | cd home       | N/A                   | cd ~                       | Moves to the home directory (Bash only).     |
    | cd previous   | N/A                   | cd -                       | Moves to the previous directory.             |
    |---------------|-----------------------|----------------------------|----------------------------------------------|
    | type/cat      | type file.txt         | cat file.txt               | Displays the contents of a text file.        |
    | more/less     | more file.txt         | less file.txt              | Views file contents one page at a time.      |
    | clear screen  | cls                   | clear                      | Clears the terminal screen.                  |
    | echo          | echo Hello            | echo "Hello"               | Prints text to the screen.                   |
    | attrib/stat   | attrib                | stat file.txt              | Displays detailed file attributes.           |
    |___________________________________________________________________________________________________________________|
*/

