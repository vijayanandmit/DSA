func reverseBits(num uint32) uint32 {
    var ans uint32 //declare as unsigned int, Java doesn't have unsigned int concept
			//go, cpp has
    pow:=31	//declare and intialize power = 31, for each bit i, should go to 31-i position in output number
    ans = 0
    for num!=0 {	// this is while loop in go
        ans += (num&1)<<pow	//semicolon is optional in go, there is no strict check on semicolon like python or cpp
        num >>= 1;		//bit shifing and assignment operators are all same in all languages
        pow -= 1;
    }

    return ans
}
