class Ente
{
public:
  int id;
public:
  Ente();
  Ente(int i);
  ~Ente();
  virtual void executar() = 0;
};
