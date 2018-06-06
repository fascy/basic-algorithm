#include <stdio.h>  
#include <stdlib.h>  

#define MAX_TREE_HT 100  

// һ�����������ڵ�  
struct MinHeapNode {
	char data;         
	unsigned freq;     
	struct MinHeapNode *left, *right;
};

// ��С��: ��Ϊ���ȶ���ʹ��  
struct MinHeap {
	unsigned size;     
	unsigned capacity;  
	struct MinHeapNode **array;
};

//��ʼ��һ����С�ѽڵ�  
struct MinHeapNode* newNode(char data, unsigned freq) {
	struct MinHeapNode* temp = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
};

// ����һ������Ϊcapacity ����С��  
struct MinHeap* newMinHeap(unsigned capacity) {
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	struct MinHeapNode **array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
	minHeap->array = array;
	return minHeap;
};

//  swap �����ѽڵ�  
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
	struct MinHeapNode* temp = *a;
	*a = *b;
	*b = temp;
}

//�õ����ӽڵ��±꣬Ĭ�ϵ�һ���ڵ��±�Ϊ0  
int getLeftIndex(int index) {
	return ((index << 1) + 1);
}

//�õ��Һ��ӽڵ��±꣬Ĭ�ϵ�һ���ڵ��±�Ϊ0  
int getRightIndex(int index) {
	return ((index << 1) + 2);
}

// ������С��  
void adjustMinHeap(struct MinHeap* minHeap, int index) {
	int less = index;
	int left = getLeftIndex(index);
	int right = getRightIndex(index);
	if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[less]->freq) {
		less = left;
	}
	if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[less]->freq) {
		less = right;
	}
	if (less != index) {
		swapMinHeapNode(&minHeap->array[less], &minHeap->array[index]);
		adjustMinHeap(minHeap, less);
	}
}

//���ѵĴ�С�Ƿ�Ϊ1  
int isSizeOne(struct MinHeap* minHeap) {
	return (minHeap->size == 1);
}

// ����Ƿ���Ҷ�ӽڵ�  
int isLeaf(struct MinHeapNode* node) {
	return !(node->left) && !(node->right);
}

// ��ӡ  
void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", arr[i]);
	printf("\n");
}

//ȡ�ö�����С�Ľڵ�  
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->size - 1];
	--minHeap->size;
	adjustMinHeap(minHeap, 0);
	return temp;
}

// ����С���в���һ���ڵ�  
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
	++minHeap->size;
	int i = minHeap->size - 1;
	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	minHeap->array[i] = minHeapNode;
}

//����һ����С��  
void buildMinHeap(struct MinHeap* minHeap) {
	int index = minHeap->size - 1;
	int i;
	for (i = (index - 1) / 2; i >= 0; --i) {
		adjustMinHeap(minHeap, i);
	}
}

// ����һ������Ϊ size����С�ѣ������� data[] �е�Ԫ�ص���С��  
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
	struct MinHeap* minHeap = newMinHeap(size);
	for (int i = 0; i < size; i++) {
		minHeap->array[i] = newNode(data[i], freq[i]);
	}
	minHeap->size = size;
	buildMinHeap(minHeap);
	return minHeap;
}

// ������������  
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
	struct MinHeapNode *left, *right, *top; 
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
	while (!isSizeOne(minHeap)) {
		left = extractMin(minHeap);
		right = extractMin(minHeap);
		top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		insertMinHeap(minHeap, top);
	}
	return extractMin(minHeap);
}

// ��ӡ����������  
void printCodes(struct MinHeapNode* root, int arr[], int top) {
	if (root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	// �����Ҷ�ӽڵ�ʹ�ӡ  
	if (isLeaf(root)) {
		printf("%c:", root->data);
		printArr(arr, top);
	}
}


// ����������������������ӡ�û�������  
void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode* root = buildHuffmanTree(data, freq, size); 
	int arr[MAX_TREE_HT], top = 0;
	printCodes(root, arr, top);
}


int main() {
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };
	//  int size = sizeof(arr)/sizeof(char);  
	int size = sizeof(arr) / sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
	return 0;
}