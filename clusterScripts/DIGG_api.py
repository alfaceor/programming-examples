import urllib2

APPKEY = 'http%3A%2F%2Fwww.example.com'
story_clean_title = 'Dell_vs_Apple_This_Time_it_s_Personal'
url = ''.join([
        'http://services.digg.com',
        '/story/%s' % story_clean_title,
        '?appkey=%s' % APPKEY,
        '&type;=json',
        ])
json = urllib2.urlopen(url).read()
print json

'http://services.digg.com/story/Dell_vs_Apple_This_Time_it_s_Personal/?appkey=http%3A%2F%2Fwww.example.com&type;=json'
'http://www.example.com'

