#include <bits/stdc++.h>

using namespace std;

struct MinHeapNode
{
    char character;
    unsigned frequency;
    MinHeapNode *left, *right;
    // Function to initialise the structure
    MinHeapNode(char character, unsigned frequency)
    {
        left = right = NULL;
        this->character = character;
        this->frequency = frequency;
    }
};

// Comparision Funciton for priority queue
struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->frequency > r->frequency);
    }
};

//Used for printing the ouput
void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
        return;
    if (root->character != '#')
        cout << root->character << "\t\t" << str << endl;
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Driver Code
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cout << "Enter the number of characters: " << endl;
    cin >> n;
    char character;
    int frequency;
    cout << "Enter the characters and their frequency: " << endl;
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;
    for (int i = 0; i < n; i++)
    {
        cin >> character;
        cin >> frequency;
        minHeap.push(new MinHeapNode(character, frequency));
    }
    // While the minheap has more than 1 element
    // pop the smallest 2 elements and add a new node with the frequency = frequency1 + frequenc2
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('#', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    cout << "The Huffman Codes are:\n";
    cout << "Character:\t\tHuffman Code\n";
    printCodes(minHeap.top(), "");
    return 0;
}
