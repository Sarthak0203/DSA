/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject)=>{

        let ans = [];
        let waiting = functions.length;
        for(let i=0;i<functions.length;i++){
            functions[i]().then((res)=>{
                ans[i]=res;
                waiting--;
                if(waiting===0) return resolve(ans)
            }).catch(reject)
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */