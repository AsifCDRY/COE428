void mySort(int d[], unsigned int n)
{
	int key, i, j;
	for(i = 1; i < n; i++) {
		key = d[i];
		j = i-1;
		
		while(j >= 0 && d[j] > key){
			d[j+1] = d[j];
			j = j-1;
		}
		d[j+1] = key;
	}
}
