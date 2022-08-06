they are living in my walls

## Installation instructions
We use [Visual Studio (Community)](https://visualstudio.microsoft.com/) (the purple one, not the blue one) for this project.

First, clone the repository `git clone <url>` where you would like it.

WxWidgets, the GUI library we're using, needs to be installed separately:
- Go to [WxWidgets downloads](https://www.wxwidgets.org/downloads/).
- Download the binaries for your system, and the Header Files:
	- Assuming you're on Windows, you need to click the blue 'Download Windows Binaries' button.
	- Download the Header Files.
	- Download the Development Files (you probably want the 64-bit version).
- Extract the downloaded ZIP files to the WxWidgets directory of the project repo.
- The WxWidgets directory should contain `build`, `include`, `lib` `EXTRACT ZIPS HERE` and `wxwidgets.props`.
- Navigate to the `WxWidgets\lib\vc14x_x64_dll` and copy its **full** file path.
- Add this file path to your Path variable:
	- On Windows, search 'environment variables' and open it (a control panel item)
	- Click the button 'Environment Variables...'
	- Select the 'Path' variable under User variables
	- Click 'Edit', then 'New' and paste the file path.
	- Click 'Ok' a few times until the menus are gone.
	- If you ever move the project directory, make sure to edit your Path variable too
- Open Visual Studio, click 'Open a project or solution'.
- Navigate to the project directory, then the Minesweeper folder followed by either of the selectable files.
