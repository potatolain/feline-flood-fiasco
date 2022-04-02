# Copy newest patch out of my downloads folder into the rom folder automatically 
cp "$(find "/c/users/owner/downloads" -name "puzzle (*).ips" -printf "%T@ %p\n" | sort -nb | tail -n1 | cut -d' ' -f2-3)" ./rom/game.ips
