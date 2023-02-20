/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        /*int cnt=-1, len=1;
        ListNode* node=head;
        int sum=0;
        while(node){
            sum+=node->val;
            if(sum==0) cnt=len;
            len++;
            node=node->next;
        }
        if(cnt==-1) return head;
        node=head;
        for(int i=0; i<cnt; i++) node=node->next;
        return node;*/
        ListNode* root =new ListNode(0);
        root->next=head;
        unordered_map<int,ListNode*> mpp;
        mpp[0]=root;
        int sum=0;
        
        while(head!=NULL){
            sum+=head->val;
            
            if(mpp.find(sum)!=mpp.end()){
                ListNode* prev= mpp[sum];
                ListNode* start= prev;
               
                int tmp = sum;
                while(prev!=head){
                    prev=prev->next;
                    tmp+=prev->val;
                    if(prev!=head)mpp.erase(tmp);
                }
                
                start->next = head->next;
            }else{
                mpp[sum]= head;
            }
            
            head=head->next;
        }
        
        return root->next;
    }
};