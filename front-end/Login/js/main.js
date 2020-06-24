$(function () {
    // ***************弹出登录***************
    function popUp(id) {
        if (id == "#login_btn") {
            $(id).on("click", function (event) {
                $(".mask")
                    .slideDown(1000);
                $(".login-wapper")
                    .delay(500)
                    .slideDown(1000);
                event.stopPropagation();
            });
        }
    }
    popUp("#login_btn");

    // ***************登录***************
    $("#liji_login").on("click", function (event) {
        event.stopPropagation();
        $(".register-wapper").fadeOut(1000);
        $(".login-wapper").delay(1000).slideDown(500);
    });


    // ***************点击空白处隐藏***************
    function hidden_popUp(popup) {
        $(document.body).on("click", function (event) {
            var target = $(event.target);
            if (event.target != target && target.closest(popup).length == 0) {
                if ($(popup).css("display") == "block") {
                    $(".mask")
                        .delay(500)
                        .fadeOut(1000);
                    $(popup)
                        .fadeOut(1000);

                }
            }
            event.stopPropagation();
        });
    }
    hidden_popUp(".login-wapper");

    // ***************点击输入框隐藏文字和边框动画***************
    function hidden_txt(id) {
        $(id).on("focus blur", function (event) {
            event.stopPropagation();
            var $this = $(this);
            if (event.type == "focus") {
                $this.siblings("span").css("color", "#666");
                // 添加边框动画
                $(".login-wapper").css("animation", "colors 20s ease infinite");
            } else if (event.type == "blur") {
                $this.siblings("span").css("color", "#fff");
                $(".login-wapper").css("animation", "none");
            }
        });
        // 隐藏输入框里面span的文字
        $(id).on("input", function (event) {
            if ($(this).val() != "") {
                $(this).siblings("span").fadeOut();
            } else {
                $(this).siblings("span").fadeIn();
            }
            event.stopPropagation()
        });
    }

    hidden_txt("#username");
    hidden_txt("#password");
    // ***************关闭提示信息***************
    $("#close_regtip").on("click", function (event) {
        event.stopPropagation();
        $(".mask2").hide();
        $(".reg-tip-box").slideUp(500);
    });
});