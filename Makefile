Game: clean
	g++ Game.cpp Players.cpp Graph_Grid.cpp Events.cpp -std=c++17 -o Game
	echo "finished"
clean:
	rm Game