all:
	g++ -c **.cpp Gerenciadores/**.cpp Entidades/**.cpp ClassesAuxiliares/**.cpp -IC:\SFML\SFML-2.5.1\include
	g++ *.o  -o sfml-app -LC:\SFML\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
	./sfml-app
clean:
	-del -fR *.exe *.o
	