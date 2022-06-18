struct Node
{
   Node *link[26];
    bool flag=false;
   
    bool containKey(char ch)
    {
        if(link[ch-'a']!=NULL)
            return true;
        else
            return false;
    }
    void put(char ch,Node *node)
    {
        link[ch-'a']=node;
    }
    Node * get(char ch)
    {
        return link[ch-'a'];
    }
    void setEnd()
    {
        flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class Trie {
        Node* root;

public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containKey(word[i])==false)
            {
                node->put(word[i],new Node());
            
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) 
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containKey(word[i])==false)
                return false;
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(node->containKey(prefix[i])==false)
                return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */