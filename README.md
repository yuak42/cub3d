_This project has been created as part of the 42 curriculum by byaprak, yuak_.

# Description

A 3D maze exploration game inspired by the classic _Wolfenstein 3D_.

The **goal** of cub3D is to create a simple 3D graphical representation of a maze using raycasting techniques. The project introduces the fundamentals of computer graphics, geometric calculations, rendering, and event handling.

cub3D renders a 3D perspective of a maze from the player's point of view. The environment is defined by a `.cub` configuration file containing map information, wall textures, and floor and ceiling colors.

The program uses raycasting to determine the distance between the player and surrounding walls, allowing it to render a pseudo-3D environment from a 2D map.

The project includes:

- Parsing and validation of map configuration files.
- Raycasting-based 3D rendering.
- Wall texture mapping.
- Player movement and camera rotation.
- Collision detection.
- Keyboard and window event handling.

# Instructions

## Requirements

- C compilers `cc` and `gcc`.
- `make`.
- MiniLibX's required system dependencies for linux.
- A supported graphical environment.
- `git`

## Compilation

After cloning repository, simply run

```sh
make
```

It will clone _MiniLibX_ and compile everything necessary.
The final executable _cub3D_ should appear after compilation.

## Execution

There are maps in the `maps/` directory, and there are necessary textures in the `textures/` directory.

To execute the program, you should give an argument as a path to a `.cub` file. Such as

```sh
./cub3D maps/01_basic.cub
```

## Controls

| Key         | Action              |
| ----------- | ------------------- |
| W           | Move forward        |
| S           | Move backward       |
| A           | Move left           |
| D           | Move right          |
| Left Arrow  | Rotate camera left  |
| Right Arrow | Rotate camera right |
| ESC         | Exit the game       |

# Resources

## Reference

- [MiniLibX Documentation](https://harm-smits.github.io/42docs/) — Graphics library documentation and usage examples.
- [Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html) — Raycasting algorithms, camera projection, and 2D-to-3D rendering concepts.

## Declaration of AI Use

AI tools were used as supplementary resources during the development of this project.

Their use included:

- **Conceptual explanations:** Clarifying raycasting, vector calculations, parsing strategies, and related programming concepts.
- **Debugging assistance:** Helping investigate errors, understand unexpected behavior, and explore possible solutions.
- **Code review and improvement:** Discussing code organization, readability, and potential improvements.
- **Documentation assistance:** Helping structure and refine project documentation.

AI-generated suggestions were used as a learning and development aid. The project code, implementation decisions, testing, and final integration were reviewed and handled by the project developers.
