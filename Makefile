all:
	g++ -c **.cpp Fases/**.cpp Gerenciadores/**.cpp Entidades/**.cpp Entidades/Obstaculos/**.cpp Entidades/Personagens/**.cpp ClassesAuxiliares/**.cpp ClassesAuxiliares/Estados/**.cpp ClassesAuxiliares/Listas/**.cpp -IC:\SFML\SFML-2.5.1\include
	g++ *.o  -o mario++ -LC:\SFML\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
clean:
	-del -fR *.exe *.o

	