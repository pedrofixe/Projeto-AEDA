#include "praias.h"

using namespace std;



praiaFluvial::praiaFluvial()
{}


praiaFluvial::praiaFluvial(string concelho, GPS gps, bool bandeirazul, unsigned int capacidade, vector<Servico> servicosdapraia) : concelho(concelho), gps(gps), bandeiraazul(bandeiraazul), capacidade(capacidade), servicosdapraia(servicosdapraia)
{}
