# Feline Flood Fiasco

This is the repository for Feline Flood Fiasco - a Ludum Dare 50 entry. Apologies for the sparse readme, but please check out 
[the base rom](https://github.com/cppchriscpp/nes-puzzle-maker-rom) to see documentation on how this thing works with a fresh start!

If you want to see what changed, [this pr](https://github.com/cppchriscpp/feline-flood-fiasco/pull/1) shows how it was done.

It was based off this: https://github.com/cppchriscpp/nes-puzzle-maker-rom

Using this tool for all of the maps, data, etc: https://puzzle.nes.science

Game code changes are in this repo, and there should also be an exported piece of json in the rom directory that can be used to play with
the game in the Retro Puzzle Maker ui. (If I forgot this, remind me! I'm sure I still have it!) 

The new data is applied via a patch exported from the puzzle maker, in an ips file in the rom directory. The final rom will be
the result of applying the patch to the rom and saving it.

Entry page: https://ldjam.com/events/ludum-dare/50/feline-flood-fiasco

Play it: https://cpprograms.net/classic-gaming/feline-flood-fiasco/