int contandoDragones(int T, int d1, int d2, int d3) {
	int cantD1 = T / d1;
    int cantD2 = T / d2;
    int cantD3 = T / d3;



    return T - (cantD1 + cantD2 + cantD3) + (T/(d1*d2*d3) +T/(d1*d2) + T/(d1*d3) + T/(d2*d3));
}
