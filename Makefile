CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = a5
OBJECTS = main.o Board.o Player.o Deck.o Card.o Spells.o Minion.o Ritual.o Enchantment.o Ability.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
