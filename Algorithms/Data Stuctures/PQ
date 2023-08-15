// based on first part in ascending and second part in
// descending first basis
class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }
 
        return false;
    }
};
 
    priority_queue<PII, vector<PII>, Compare> ds;
