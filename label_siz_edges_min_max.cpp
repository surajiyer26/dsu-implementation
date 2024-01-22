int label [300005];
int siz [300005];
int edges [300005];
int minele [300005];
int maxele [300005];

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
	maxele[lb] = max(maxele[la], maxele[lb]);
	minele[lb] = min(minele[la], minele[lb]);
	label[la] = lb;
}
