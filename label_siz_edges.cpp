int label [150005];
int siz [150005];
int edges [150005];

int find_label (int x) {
	if (label[x] == x) return x;
	return label[x] = find_label(label[x]);
}

void merge (int a, int b) {
	int la = find_label(a);
	int lb = find_label(b);
	edges[la] += 1;
	if (la == lb) return;
	if (siz[la] > siz[lb]) swap(la, lb);
	siz[lb] += siz[la];
	edges[lb] += edges[la];
	label[la] = lb;
}
