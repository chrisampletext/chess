CXX = g++
CXXFLAGS = -Wall -g -MMD
EXEC = chess
OBJECTS = main.o board.o player.o piece.o pawn.o king.o rook.o queen.o bishop.o knight.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean