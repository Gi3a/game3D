# game3D

## Simple 3D game on C
The goal of cub3d is to make something using raycasting (like Wolfenstein 3D).
![alt tag](https://github.com/Gi3a/game3D/blob/main/screen.png)
* WASD to move, QE or Left/Right directional keys to rotate camera
* ESC to quit
* Textures or colors for each sides (North, South, West, East) and Sky/Floor
* Shadows based on the distance
* Crosshair
* 3 different sprites

## Start
```./cub3D maps/midi.cub```
or
```./cub3D maps/midi.cub -s (to make screenshot)```

## You can now create your own map:
| Object | Code |
| 1 | wall |
| 0 | floor |
| 2 | sprite |
| N/E/W/S | player initial position + orientation |
