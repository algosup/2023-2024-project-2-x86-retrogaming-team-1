# 2023-2024-project-2-x86-retrogaming-team-1

## Project Description

The 2nd project of the 2023-2024 school year is to recreate the classic Pac-Man in assembly x86 on DosBox.

## Team Members

| Name | Role | Picture |
| --- | --- | --- |
| [Alexis Lasselin](https://github.com/alexislasselin) | Project Manager | <img src="https://avatars.githubusercontent.com/u/114481578?v=4" width=15%> |
| [Grégory Pagnoux](https://github.com/Gregory-Pagnoux) | Program Manager | <img src="https://avatars.githubusercontent.com/u/114397869?v=4" width=15%> |
| [Salaheddine Namir](https://github.com/T3rryc) | Technical Leader | <img src="https://avatars.githubusercontent.com/u/71770514?v=4" width=15%> |
| [Jason Grosso](https://github.com/JasonGROSSO) | Software Engineer "Senior" | <img src="https://ca.slack-edge.com/T065235SLD6-U06523H78EL-gd1a42f2c990-512" width=15%> |
| [Abderrazaq Makran](https://github.com/Amakran2003) | Software Engineer "Junior" | <img src="https://ca.slack-edge.com/T065235SLD6-U06523HAB16-gfef8c5bc507-512" width=15%> |
| [Victor Leroy](https://github.com/Victor-Leroy) | Quality Assurance | <img src="https://avatars.githubusercontent.com/u/97166029?v=4" width=15%> |

## How to play

### Requirements

To play the game, you will need to install [DosBox](https://www.dosbox.com/download.php?main=1) and to download the .zip file of this GitHub Project and unzip it.

If you are on MacOS, you must ensure that Dosbox is installed in the Applications folder. While on Windows, you don't need to do anything, because the installer is automatically installing Dosbox in the Program Files folder.

### Launching the game

Then, depending on your operating system, you must follow the following instructions:

On MacOS:

Open the terminal and move to where your unzipped folder is located. Then, you must type the following command:

```bash
cd src
./build.bash
```

On Windows:

Open the file explorer and move to the folder where your unzipped folder is located. Then, you must go in the `src` folder and double click on the `build.cmd` file.

In both cases, the game will be compiled, open dosbox and launch the game automatically.

### Playing the game

Once the game is launched, you will be able to play it. To move PAC-MAN, you must use the arrow keys.

#### Warning

We implemented some sounds in the game, but sometimes, depending on the machine, the sound may be a bit aggressive for the ears. So, we recommend you to lower the volume of your computer before playing the game, especially if you are wearing headphones.

## Project Management

### GitHub Project

Because Trello is not adapted to GitHub's projects, we decided to use GitHub's projects because they are directly linked to the repository, allowing us to link our pull requests and issues to the tasks.

This GitHub Project is getting 3 different ways to be used:

- The Trello version, where you can find all the differents tasks placed depending of their completion level;
- The task list, that is just a list of all the project's related tasks done during the project's period (As an example, learning assembly was essential but not written inside, because it wasn't a required task);
- The Roadmap version, that is a Gantt chart that shows the project's progression. The only problem is that is not allowing us to link the tasks to create dependencies.

[Link to the GitHub Project](https://github.com/orgs/algosup/projects/14/views/4)

### Project Follow-up

Instead of a Gantt chart, we created a Project Follow-up on Google Sheets. Obviously, the result is not as good as a Gantt chart but it is still a good way to follow the project's progress.

[Link to the Project Follow-up](https://docs.google.com/spreadsheets/d/1jwxQr9kJG0H953cxi_KhxmUx7Of77138Xc5UtYZcYdA/edit?usp=sharing)
