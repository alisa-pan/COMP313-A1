# COMP313-A1

## Assignment 1: "Crow Game"
## Alisa Panchavinin

## Game description
### Main action 
The main action in the game is the movement of the crow around the playing space and its interactions with the apples. 

In my game, the player controls a crow character around the world using WASD to move around and SPACE to jump. The player can also pivot the camera left to right and up and down by moving the mouse. When the game starts, a bunch of apples are generated at random (x, y) locations all around the world (z value stays the same), and there are two deer NPCs that run around. 

The goal of the game is to 'eat' more apples than the deer. When the crow collides with an apple, it eats half of it, so the crow colliding with an apple twice will eat the whole apple. A deer colliding with an apple once will eat the whole apple. 

A deer colliding with the crow will teleport the crow to another location by swapping around the crow's x and y coordinates, so if the crow and a deer are both heading towards the same apple, the deer could collide with the crow and teleport it far away from the apple. 

There is also a trigger box that the character can overlap with. When this happens, more apples are generated in the world. 


### Hardest part
The hardest part to implement for me was the settings menu. In my settings menu, I have a slider that allows the player to choose how many apples are generated at the start of the game, and a checkbox toggle to turn sound on and off. A problem I kept running into at first was that, although I could change the settings in the menu and they would have an effect on the game the next time it was played, when I returned to the settings menu, the slider and/or checkbox would be back in their default state no matter what the state of those variables were (e.g., the sound toggle could be its default checked (indicating sound on) even though the game was actually muted, and the slider would be set to its default 5, even though the game was generating a different number of apples). To fix this, I had to create a game instance and store variables for sound and apple numbers in there, essentially treating them as a sort of global variable that was retained even when the levels were reset. In the end I found this good learning for me to practice casting to things that weren't my player character. 


### Most interesting part
The part I found most interesting to do were the animations. I really liked making the animation state machines and thinking about what states should be allowed to transition to each other and what rules and booleans I needed to have in order to make those transitions successful. It was definitely cool to see a practical application of state machines as well.

The part of the game that I think is most interesting during playing is probably the NPCs. 

## Other notes:
- Here is the tutorial I used to really get started. I began with a blank template, which I found incredibly intimidating, but I think I learned a lot by doing it that way. 

- Some of my commits don't match up with the files I talk about in the commit message. I was still learning how to use git and I got a bit confused along the way, but all the commits after 0ba8a4f should be fine. Most of the ones before it are fine, too, there are just a few in the middle. 