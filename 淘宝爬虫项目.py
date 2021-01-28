import re
from selenium import webdriver
import time


def Search_Product(explorer,ProductName):
    explorer.find_element_by_xpath('//*[@id="q"]').send_keys(ProductName)
    explorer.find_element_by_xpath('//*[@id="J_TSearchForm"]/div[1]/button').click()
    time.sleep(5)#10s时间进入登陆界面进行扫码登陆
    #下面就可以提取总页面了

def Down_To_Bottom(explorer):#滑动下滑条把整个页面加载出来，因为用到了js代码，参考了csdn上的代码
        position='var q=document.documentElement.scrollTop=10000'
        explorer.execute_script(position)#拉到最后，全部加载

def Get_Product(explorer,information,PriceMin,PriceMax,SalesVolumeMin):#字典，打印出来，如果有余力可以保存到excel中，写第二个爬虫获取评论
    allproducts=explorer.find_elements_by_xpath('//div[@class="items"]/div[@class="item J_MouserOnverReq  "]')
    for eachproduct in allproducts:
        salesvolume=eachproduct.find_element_by_xpath('.//div[@class="deal-cnt"]').text
        salesvolume=re.search('(\d+)',salesvolume).group(1)
        if eval(salesvolume)<SalesVolumeMin:
            continue
        price=eachproduct.find_element_by_xpath('.//div[@class="price g_price g_price-highlight"]/strong').text
        if eval(price)>PriceMax or eval(price)<PriceMin:
            continue
        url=eachproduct.find_element_by_xpath('.//div[@class="row row-2 title"]/a').get_attribute('href')
        message={'销量':salesvolume,'价格':price,'链接':url}
        print(message)
        information.append(message)#可以用一个列表append这个information

def Get_Allpages(explorer):#获取所有页数，确定翻页的循环次数
    dat=explorer.find_element_by_xpath('//div[@class="total"]').text
    digit=re.search('(\d+)',dat)#提取出总页数
    return int(digit.group(1))

def Turn_Pages(explorer,ProductName,OriginPage):#淘宝反爬会发验证码，为了避免可以改url的参数，翻页,每次改变页面都只修改一个url参数,每次翻一页动44，另外根据搜索内容不同对q后面的参数进行修改
    NewUrl='https://s.taobao.com/search?q={0}&imgfile=&commend=all&ssid=s5-e&search_type=item&sourceId=tb.index&spm=a21bo.2017.201856-taobao-item.1&ie=utf8&initiative_id=tbindexz_20170306&bcoffset=-3&ntoffset=-3&p4ppushleft=1%2C45&s={1}'.format(ProductName,OriginPage)
    explorer.get(NewUrl)

def Process(explorer,OriginPage):#现在是第二页
    Down_To_Bottom(explorer)#拉到底部加载
    Get_Product(explorer,information,PriceMin,PriceMax,SalesVolumeMin)#获取信息
    Turn_Pages(explorer,ProductName,OriginPage)#翻页

def Run_Process(explorer,ProductName,OriginPage):#最后的封装
    Search_Product(explorer,ProductName)
    #登陆
    Down_To_Bottom(explorer)
    AllPages=Get_Allpages(explorer)
    Get_Product(explorer,information,PriceMin,PriceMax,SalesVolumeMin)
    Turn_Pages(explorer,ProductName,OriginPage)
    #下面开始对每一页进行提取操作
    for i in range(AllPages-2):#减去第一页，不用翻页 3页要翻两次
        OriginPage += 44
        Process(explorer,OriginPage)#这里process我没有传入text，因为我发现每次翻页都要更新text，索性就用xpath了

#1.用chrome打开淘宝网，并且输入框搜索
ProductName=input('请输入要购买商品的名子：')
PriceMin=eval(input('请输入期望商品价格最小值：'))
PriceMax=eval(input('请输入期望商品价格最大值：'))
SalesVolumeMin=eval(input('请输入期望的商品最低销量：'))
information=[]
OriginPage=44
explorer=webdriver.Chrome()
explorer.get("https://www.taobao.com/")
Run_Process(explorer,ProductName,OriginPage)#开始爬虫
#2.出现新问题，每一页竟然只采集了一个数据，这是为什么
#是因为停留时间太短导致采集信息只够一个？还是压根在遍历的时候出现代码的bug
#在downtobuttom的时候睡了10s仍然之采集一个，说明是代码的bug
#问题出在getproduct中的find_elements_by_xpath,不能直接复制xpath路径，不然是div[1]，要找每一个必须确定其class，而不是索引
#修改了xpath路径，问题解决，每一页都采集48个数据再翻页，完成



