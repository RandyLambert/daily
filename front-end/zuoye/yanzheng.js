function panduanyonghu(str1, str2, str3) {
    var flag = true;
    if (str1.length < 0 || str2.length < 0 || str3.length < 0) {
        alert("请将空填写完整");
        return false;
    }
    if (str1 == "test1234") {
        alert("检查旧密码是否输入正确");
        flag = false;
    }
    if (str2 != str3) {
        alert("请确认,新密码和确认新密码是否相同");
        flag = false;
    }
    return flag;
}

var temp = document.getElementById('queren');
temp.onclick = function () {
    var st1 = document.getElementById('s1').value;
    var st2 = document.getElementById('s2').value;
    var st3 = document.getElementById('s3').value;
    console.log(st1.length);
    console.log(st2.length);
    console.log(st3.length);
    let x = panduanyonghu(st1, st2, st3);
    if (x == true) {
        let rg1 = /[a-zA-Z1-9]{6,16}/;
        let rg2 = /[a-z]/i;
        let rg3 = /[1-9]/;
        console.log(rg1.test(st2));
        console.log(rg2.test(st2));
        console.log(rg3.test(st2));
        if (rg2.test(st2) && rg1.test(st2) && rg3.test(st2))
            alert("登录成功!");
        else
            alert("密码规则：长度至少6位，必须包括数字和字母。");
    }

}