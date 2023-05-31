# Baba Is You
Implementation of famous Baba Is You from scratch using C++20

## Brief description
We have designed a pleasant and easy to use visual interface for users with all our functionalities via shortcuts, buttons and an application menu. Our application is not responsive (resize unavailable) and is designed for DESKTOP devices only. Sprites are only loaded once (using a single spritesheet) by the view to avoid progressive overloading.

## Building and launch

To build the project, the `working directory` of this project must be (from the 'BabaIsYou' root) : `/src` and launch it with your favourite C++ IDE.

## Features
- Save a game and giving a name to it
- Load a game
- Display a help menu
- Restart the current level
- Play to the 5 firsts levels of Baba is You

## Remarks

* One advertissement : GuiView::displayUserSaves : Pass a context object as 3rd connect parameter.
* 2 uses of 'new' are listed in the code without delete (for the creation of views) but via this attribute: setAttribute(Qt::WA_DeleteOnClose), the delete is implicitly called when necessary
* You can play in the console by following the instructions in main.cpp

## Code 

* Using a MVC pattern
* Using Facade pattern
* Using Observable-Observer
* Graphic view using QT 
* Unit Tests with Catch2
* CMake project

## Authors

* Cameron Noupoue
* Rida Belkhiri

## Credits

Project devised and created during my studies at the École Supérieure d'Informatique (ESI), Brussels.

Images from this [wiki](https://babaiswiki.fandom.com/wiki/Baba_Is_You_Wiki)
