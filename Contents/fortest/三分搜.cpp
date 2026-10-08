struct node{
	double x, y;
}arr[n];
 
double check(double val) {
	double cmax = 0;
	for(int i = 0; i < n; i++) {
		cmax = max(cmax,(arr[i].x - 0) * (arr[i].x - 0) + 
                   (arr[i].y - val) * (arr[i].y - val));
	}
	return cmax;
}
 
while(r - l > eps) {
	double ml = l + (r - l) / 3;
	double mr = r - (r - l) / 3;
	if (check(ml) < check(mr)) {
		r = mr;	
	}
	else {
		l = ml;
	}
}