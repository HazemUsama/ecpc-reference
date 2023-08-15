void remove(idx);  // TODO: remove value at idx from data structure
void add(idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}

//~ Based on the problem we can use a different data structure and modify the add/remove/get_answer functions accordingly. For example if we are asked to find range sum queries then we use a simple integer as data structure, which is  
//~ $0$  at the beginning. The add function will simply add the value of the position and subsequently update the answer variable. On the other hand remove function will subtract the value at position and subsequently update the answer variable. And get_answer just returns the integer.

//~ For answering mode-queries, we can use a binary search tree (e.g. map<int, int>) for storing how often each number appears in the current range, and a second binary search tree (e.g. set<pair<int, int>>) for keeping counts of the numbers (e.g. as count-number pairs) in order. The add method removes the current number from the second BST, increases the count in the first one, and inserts the number back into the second one. remove does the same thing, it only decreases the count. And get_answer just looks at second tree and returns the best value in  
//~ $O(1)$ .
