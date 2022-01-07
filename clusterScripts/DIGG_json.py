import simplejson
import urllib2
from pprint import pprint

APPKEY = 'http%3A%2F%2Fwww.example.com'

def main():
    story_clean_title = 'Dell_vs_Apple_This_Time_it_s_Personal'


    # get story
    json = get_json('/story/%s' % story_clean_title)
    print '---- HELLO ----'
    pydata = simplejson.loads(json)
    story_id = pydata['stories'][0]['id']

    # get comments
    json = get_json('/story/%s/comments' % story_id)
    pydata = simplejson.loads(json)
    pprint(pydata)

def get_json(endpoint):
    """ returns json data for requested digg endpoint 
    """
    url = ''.join([
            'http://services.digg.com',
            endpoint,
            '?appkey=%s' % APPKEY,
            '&type;=json',
            ])
    return urllib2.urlopen(url).read()

if __name__ == '__main__':
    main()

