class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> need(256,0);
        vector<int> have(256,0);
        
        int n=t.length();
        
        //store frequency of char of t
        for(auto ch:t){
            need[ch]++;
        }
        
        int left=0;
        int right=0;
        int len=INT_MAX;
        int start=-1;
        
        int count=0;
        
        while(right<s.length()){
            
            //store frequency of char of s in "have" vector
            have[s[right]]++;
            
            
            // jitni quantity kisi char ki jarurat hai agar utna hai ya usse kam h 
            // to count badha do
            
            // why less than equal to?
            // s: "AA"  t: "AA"
            // at right=0 , s : A->1 , t : A->2 but count has to be increased
            if(have[s[right]]<=need[s[right]]){
                count++;
            }          
            
            //Jb count t ke length ke barabar ho jaye to possible answer mil skta hai
            if(count==n){
                
                // need[s[left]]==0 mtlb ye "have" vector m h
                // pr iski jarurat nhi kyo ki ye char "need" m nhi h
                
                // have[s[left]]>need[s[left]] mtlb "have" m ye char jyada times h need se
                // and hmlog ki min nikalna h to ignore kro mtlb left ko aage badhao
                // and uska count ghatao vector me
                while(need[s[left]]==0 || have[s[left]]>need[s[left]]){
                    
                    if(have[s[left]]>need[s[left]]){
                        have[s[left]]--;
                    }
                    left++;
                }
                
                // ek bar bekar ke char ko hta diye to ab left sahi jagah pr h
                // len compare kr lo
                if(right-left+1 < len){
                    len=right-left+1;
                    start=left;
                }                                    
            }
            
            right++;
        }
        
        //Agar empty string hai ya "t" ka size "s" se bada hai to empty string return kro
        if(start==-1){
            return "";
        }
        else{
            //substring return kr do
            return s.substr(start,len);
        }
               
    }
};