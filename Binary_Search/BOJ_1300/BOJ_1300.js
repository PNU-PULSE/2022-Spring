function solution(data) {
    const [N, K] = data.split('\n').map(Number);

    let left = 1, right = K, mid;

    while(left <= right) {
        mid = Math.floor((left + right) / 2);
        if (getIndex(mid, N) >= K) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    
    const d = getIndex(mid, N);
    if (d == K) {
        console.log(mid);
    }
    else if (d < K) {
        console.log(++mid);
    }
    else {
        console.log(mid);
    }
}

function getIndex(n, N) {
    let t = 0;
    for (let i = 1; i <= N; i++) {
        t += Math.min(Math.floor(n/i), N);
    }
    return t;
}


let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

solution(input);


// solution('3\n7');
// solution('5\n18');
// solution('5\n17');