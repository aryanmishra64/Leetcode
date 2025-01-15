class Solution {
public:
    bool isSet(int &x,int bits){
        return x&(1<<bits);
    }

    bool setBit(int &x,int bits){
        return x|=(1<<bits);
    }

    bool Unset(int &x,int bits){
        return x&=  ~(1<<bits);
    }



    int minimizeXor(int num1, int num2) {

        int x=num1;

        int requiredSetBit=__builtin_popcount(num2);
        int currentSetBit=__builtin_popcount(x);

        int bits=0;

        if(currentSetBit<requiredSetBit){
            while(currentSetBit<requiredSetBit){
                if(!isSet(x,bits)){
                    setBit(x,bits);
                    currentSetBit++;
                }
                bits++;

            }
        }
        else if(currentSetBit>requiredSetBit){
            while(currentSetBit>requiredSetBit){
                if(isSet(x,bits)){
                    Unset(x,bits);
                    currentSetBit--;
                }
                bits++;
            }
        }
        return x;
        
    }
};