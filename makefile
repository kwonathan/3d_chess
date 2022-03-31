3d_chess: main.o cube.o piece.o bishop.o king.o knight.o pawn.o queen.o rook.o unicorn.o
	g++ -g main.o cube.o piece.o bishop.o king.o knight.o pawn.o queen.o rook.o unicorn.o -o 3d_chess

main.o: main.cpp helper.cpp cube.h piece.h rook.h bishop.h knight.h unicorn.h queen.h king.h pawn.h
	g++ -Wall -Wextra -g -c -std=c++11 main.cpp helper.cpp

cube.o: cube.cpp cube.h piece.h
	g++ -Wall -Wextra -g -c -std=c++11 cube.cpp
piece.o: piece.cpp piece.h
	g++ -Wall -Wextra -g -c -std=c++11 piece.cpp

bishop.o: bishop.cpp bishop.h piece.h
	g++ -Wall -Wextra -g -c -std=c++11 bishop.cpp
king.o: king.cpp king.h piece.h
	g++ -Wall -Wextra -g -c -std=c++11 king.cpp
knight.o: knight.cpp knight.h piece.h
	g++ -Wall -Wextra -g -c -std=c++11 knight.cpp
pawn.o: pawn.cpp pawn.h piece.h
	g++ -Wall -Wextra -g -c -std=c++11 pawn.cpp
queen.o: queen.cpp queen.h piece.h
	g++ -Wall -Wextra -g -c -std=c++11 queen.cpp
rook.o: rook.cpp rook.h piece.h
	g++ -Wall -Wextra -g -c -std=c++11 rook.cpp
unicorn.o: unicorn.cpp unicorn.h piece.h
	g++ -Wall -Wextra -g -c -std=c++11 unicorn.cpp

clean:
	rm -f *.o 3d_chess