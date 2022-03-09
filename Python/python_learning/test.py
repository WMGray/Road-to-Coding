# 测试代码
import unittest
from name import get_fotmatted_name

class name_test(unittest.TestCase):
  '''测试函数'''
  def test_name(self):
    username1 = get_fotmatted_name('RC','Jn')
    self.assertEqual(username1,'RC Jn'.title())
    
  def test_middle_name(self):
    '''测试带有中间名字'''
    username2 = get_fotmatted_name('RC','Jn',middle='Rbq')
    self.assertEqual(username2,'RC Rbq Jn'.title())
 

# 测试AnonymousSurvey类
import unittest
from survey import AnonymousSurvey

class TestAnonymousSurvey(unittest.TestCase):
  '''针对AnonymousSurvey类的测试'''
  def test_store_response(self):
    '''测试单个答案会被妥善的存储'''
    question = "What language did you forst learn to speak?"
    my_survey = AnonymousSurvey(question)
    response = "Chinese"
    my_survey.store_response(response)
    self.assertIn("Chinese",my_survey.response)

  def test_store_responses(self):
    '''测试多个答案会被妥善的存储'''
    question = "What language did you forst learn to speak?"
    my_survey = AnonymousSurvey(question)
    responses = ["Franch",'English','C嘉嘉']
    for language in responses:
       my_survey.store_response(language)
    for response in responses:
      self.assertIn(response,my_survey.response)


class TestAnonymousSurvey2(unittest.TestCase):
  '''针对AnonymousSurvey类的测试'''
  def setUp(self):
    '''创建一个调查对象和一组答案 供使用的测试方法使用'''
    question = "What language did you forst learn to speak?"
    self.my_survey = AnonymousSurvey(question)
    self.responses = ['C嘉嘉', '`~~`','Chinese']

  def test_store_response(self):
    '''测试单个答案会被妥善的存储'''
    self.my_survey.store_response(self.responses[0])
    self.assertIn(self.responses[0],self.responses)

  def test_store_responses(self):
    '''测试多个答案会被妥善的存储'''
    for language in self.responses:
       self.my_survey.store_response(language)
    for response in self.responses:
      self.assertIn(response,self.my_survey.response)

if __name__ == '__main__':
  unittest.main()


 