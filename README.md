# Ludum Dare 50 thing

This is the future home of a Ludum Dare entry.

It was built largely with this: https://github.com/cppchriscpp/nes-puzzle-maker-rom

Using this tool: https://puzzle.nes.science

Game code changes are in this repo, and there should also be an exported piece of json in the rom directory that can be used to play with
the game in the Retro Puzzle Maker ui. (If I forgot this, remind me! I'm sure I still have it!) 

The new data is applied via a patch exported from the puzzle maker, in an ips file in the rom directory. The final rom will be
the result of applying the patch to the rom and saving it.