function counter(N) {
    var len = N.length;
    var middle;
    if (len%2==1) {
        middle = Math.floor(len/2);
    } else {
        middle = len/2;
    }
    var sum = 0;
    var tmp;
    for (i=0; i<middle; i++) {
        tmp = N%10;
        sum += tmp;
        N = (N-tmp)/10;
    }
    alert(" "+sum);
}