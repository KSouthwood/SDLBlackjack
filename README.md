# SDLBlackjack
Blackjack written in C++ using the SDL2 library.

This is a re-write of my C++ Nanodegree Capstone project on Udacity.
I wanted to do things in a better(?) way than I did for the project where the
main goal was just to finish the program in a working state while fulfilling
the requirements.

#### Main Changes
* Loading the textures used as individual objects as opposed to loading them in when
needed.
* Have the renderer as an object in the controller class to simplify calls.
* Incorporate the render into the texture objects so they can render themselves.

