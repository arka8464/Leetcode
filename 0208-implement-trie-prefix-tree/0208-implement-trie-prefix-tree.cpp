struct Node
{
   Node *link[26];// ekta link er arr banachi jate porer tr jonyo reference nodes banate pari at max 26 ta char e to hote pare tai len 26
    bool flag=false;
   
    bool containKey(char ch)//mane reference node ta fake ache ki nei check korar jonyo
    {
        if(link[ch-'a']!=NULL)
            return true;
        else
            return false;
    }
    void put(char ch,Node *node)// ei fn ta char ch er against e link array te ekta node banche 
    {
        link[ch-'a']=node;
    }
    Node * get(char ch)
    {
        return link[ch-'a'];
    }
    void setEnd()//last reference trie bananor jonyo
    {
        flag=true;
    }
    bool isEnd()//flag ta check kore jodi null hoi tr mane kono ekta word ekhane end hoyechilo
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
            if(node->containKey(word[i])==false)//jodi reference node faka thake tobe notun node create korbo
            {
                node->put(word[i],new Node());
            
            }
            node=node->get(word[i]);//eta  last reference trie te chole jabe
        }
        node->setEnd();//last reference trie bananor jonyo
    }
    
    bool search(string word) 
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containKey(word[i])==false)//char ta present nei  
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