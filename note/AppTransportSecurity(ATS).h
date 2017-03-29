
#pragma mark - iOS9引入了新特性ATS
iOS9引入了新特性App Transport Security (ATS)。详情：App Transport Security (ATS) @"https://developer.apple.com/library/content/releasenotes/General/WhatsNewIniOS/Articles/iOS9.html#//apple_ref/doc/uid/TP40016198-DontLinkElementID_13"

新特性要求App内访问的网络必须使用HTTPS协议。
但是现在公司的项目使用的是HTTP协议，使用私有加密方式保证数据安全。现在也不能马上改成HTTPS协议传输。

#pragma mark - 临时解决方案

以下解决办法：
在Info.plist中添加NSAppTransportSecurity类型Dictionary。
在NSAppTransportSecurity下添加NSAllowsArbitraryLoads类型Boolean,值设为YES


#pragma mark - 隐患
补充说明
上面介绍的方法虽然解决了网络访问的问题，但是苹果提供的安全保障也被关闭了。
不过，按照国内的现状，关闭这个限制也许是更实际的做法。
至于原因就太多了，第三方SDK（几乎都是访问HTTP），合作伙伴接入（不能要求它们一定要支持HTTPS）。
如果你的App没有受到这些原因的限制，还是更建议你增加HTTPS支持，而不是关闭限制。
请大家根据项目的实际情况作调整。


#pragma mark - 例外
出于安全考虑我们提倡使用HTTPS，退而求其次，优先考虑使用例外：将允许访问的域加入到配置列表中

对于实在不支持HTTPS的应该首先考虑添加例外

添加例外的方式也很简单：
左键Info.plist选择open with source code
然后添加类似如下的配置:

<key>NSAppTransportSecurity</key>
<dict>
<key>NSExceptionDomains</key>
<dict>
<key>qq.com</key>
<dict>
<key>NSIncludesSubdomains</key>
<true/>
</dict>
<key>sina.com.cn</key>
<dict>
<key>NSIncludesSubdomains</key>
<true/>
</dict>
</dict>
</dict>
根据自己需要的域名修改， NSIncludeSubdomains 顾名思义是包括子域的意思
