# COMP313-A1

## COMP313
### Alisa Panchavinin

## Assignment 1: "Crow Game"


## Link to video
I have to warn you about my video. Basically, I tried so many times to screen record playing my game and doing a voiceover, but the recording would always just lag way too much to really be able to see what was going on in the game. In the end I had to use my phone to film my laptop screen and then put subtitles over the video. So that's the gameplay part of the video. It doesn't look great but hopefully you can get the feel of my game from it. I was able to screen record myself talking about the blueprints for the rest of the video without too much lag, but the audio is a little echoey. Honestly I'm so sorry for the state of my video. It was pretty much the best I could do with what I had. Anyway, you can play/download it [here](https://drive.google.com/file/d/1SGClkIDTOX51oAI-G7FieWnMZT0zQstU/view?usp=sharing). It's actually 11 minutes (sorry about that too) but it should be fine to play at a higher speed, I don't talk very fast. 

Also I couldn't include showing the C++ to blueprint nodes in the video because it was already over time, but they are the UPROPERTY fields in the AppleActor and MyCharacter classes, and you can find them in the header files for those classes inside Source/panchaalis_A1. 

## Game description
### Main action 
The main action in the game is the movement of the crow around the playing space and its interactions with the apples. 

In my game, the player controls a crow character around the world using WASD to move around and SPACE to jump. The player can also pivot the camera left to right and up and down by moving the mouse. When the game starts, a bunch of apples are generated at random (x, y) locations all around the world (z value stays the same), and there are two deer NPCs that run towards the apples.

The goal of the game is to 'eat' more apples than the deer. When the crow collides with an apple, it eats half of it, so the crow colliding with an apple twice will eat the whole apple. A deer colliding with an apple once will eat the whole apple. 

A deer colliding with the crow will teleport the crow to another location by swapping around the crow's x and y coordinates, so if the crow and a deer are both heading towards the same apple, the deer could collide with the crow and teleport it far away from the apple. 

There is also a trigger box that the crow can overlap with. When this happens, more apples are generated in the world. 


### Hardest part
In general, the steep learning curve was the hardest part and I spent many days not even knowing where to start. Once I kind of got the hang of it, though, the hardest part to implement for me ended up being the settings menu. 

In my settings menu, I have a slider that allows the player to choose how many apples are generated at the start of the game, and a checkbox toggle to turn sound on and off. A problem I kept running into at first was that, although I could change the settings in the menu and they would have an effect on the game the next time it was played, when I returned to the settings menu, the slider and/or checkbox would be back in their default state no matter what the state of those variables were (e.g., the sound toggle would be its default checked (indicating sound on) even though the game was actually muted, and the slider would be set to its default 5, even though the game was generating a different number of apples). 

To fix this, I had to create a game instance and store variables for sound and apple numbers in there, essentially treating them as a sort of global variable that was retained even when the levels were reset. In the end I found this good learning for me to practice casting to things that weren't my player character (when I had to cast to the game instance to get its variables), and it was also good learning about what a game instance could be used for. 

### Most interesting part
From a developer perspective, the part I found most interesting to do were the animations. I really liked making the animation state machines and thinking about what states should be allowed to transition to each other and what rules and booleans I needed to have in order to make those transitions successful. It was definitely cool to see a practical application of state machines as well.

From a player perspective, the part of the game that I think is most interesting during playing is probably the NPCs. I like that colliding with them can send you halfway across the map but in a predictable way. If someone got really good at knowing their (x, y) coordinates in the game, they could probably use the crow-deer collision as a strategy to transport themselves closer to certain apples. 

## Other notes:
- [Here](https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/CPPTutorials/FirstPersonShooter/) is the tutorial I used to really get started, especially with making my third-person character from scratch. I began with a blank template, which I found incredibly intimidating, but I think I learned a lot by doing it that way. 

- Some of my commits don't match up with the files I talk about in the commit message. I was still learning how to use git and I got a bit confused along the way, but all the commits after 0ba8a4f should be fine. Most of the ones before it are fine, too, there are just a few in the middle, around when I imported marketplace assets and got overwhelmed with the sheer number of new files. I ended up missing some files and not committing them when I should have. 