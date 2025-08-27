/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
var removeKdigits = function(num, k) {
    let stack = [];
    for(digit of num){
        while(k && stack.length && stack[stack.length - 1] > digit){
            stack.pop();
            k--;
        }
        stack.push(digit);
    }
        while(k && stack.length){
            stack.pop();
            k--;
        }
        let i=0;
        let ans = stack.join('');
        while(i<ans.length && ans[i] == '0') i++;
        ans=ans.slice(i);
        return ans==""?"0":ans;
        
};