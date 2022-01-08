# cub3D
3D game using raycasting.

<img src="https://github.com/Eflox/cub3D/blob/main/Pictures/Screenshot1.png" width="300"> <img src="https://github.com/Eflox/cub3D/blob/main/Pictures/Screenshot2.png" width="300">


## Compilation & Execution

To play the game
```
make re && ./Cub3D map/minimalist.cub
```

To save the first rendered image in bmp format
```
make re && ./Cub3D map/minimalist.cub --save
```

## Instructions

* ```WASD``` to move
* ```Left/Right``` directional keys to rotate camera
* ```ESC``` to quit

## Map File

### Settings

* ```R``` Resolution
* ```NO/SO/WE/EA``` Wall textures file path
* ```S``` Object file path
* ```F/C``` Floor & ceiling color

### Map Key

* ```1``` Walls
* ```0``` Empty Spaces
* ```2``` Object
* ```NESW``` Direction of player spawn


<img src="https://github.com/Eflox/cub3D/blob/main/Pictures/Map.png" width="300">
