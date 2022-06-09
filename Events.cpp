#include "Declaration.h"

void Flu::Affect(Player *player) const {
  int randNum = 100 * (double(rand()) / (RAND_MAX + 1ll));
  bool flag = false;
  if (player->GetHealthLevel() < 5) {
    if (randNum < 80) flag = true;
  } else if (player->GetHealthLevel() < 10) {
    if (randNum < 50) flag = true;
  } else if (player->GetHealthLevel() < 20) {
    if (randNum < 20) flag = true;
  }
  if (flag) {
    player->AddHealthLevel(-2);
    player->AddMentalLevel(-1);
  }
}
void SportsMeeting::Affect(Player *player) const {
  int randNum = 100 * (double(rand()) / (RAND_MAX + 1ll));
  bool flag = false;
  if (player->GetHealthLevel() < 5) {
    if (randNum < 80) flag = false;
  } else if (player->GetHealthLevel() < 10) {
    if (randNum < 50) flag = false;
  } else if (player->GetHealthLevel() < 20) {
    if (randNum < 20) flag = false;
  }
  if (flag) {
    player->AddHealthLevel(2);
    player->AddMentalLevel(1);
  }
}
void FallInLove::Affect(Player *player)const{
if(player->GetLoveStage()==0)
{
  cout<<"当你端着咖啡小心翼翼地从麦斯威门口的人群中挤过时，一缕发丝轻轻从你的手上拂过，带着一丝若有若无的矢车菊的味道。"<<endl;
  cout<<"你不由得转过身，越过一排头顶向不远处望去，你看见那个姑娘也转过头来看你。她笑着拢起头发，朝你吐了吐舌头，然后转身走开了。"<<endl;
  cout<<"突然你感觉心底里有处柔软的地方被触动了，你咽了口唾沫，用力挤出人群，却只看见那个女孩的身影消失在走廊的尽头。"<<endl;
  int choice=-1;
  cout<<"输入0追上去,输入1转身离开"<<endl;
  while(choice!=0&&choice!=1)
  {
    cin>>choice;
  }
  if(choice==0)
  {cout<<"你追了上去，即使结局可能会如往昔一般落寞。"<<endl;
  if(player->GetCharmLevel()>=7)
  {
    cout<<"即使心有忐忑，但你成功了。此后，两颗心的距离进了一些。（按任意键以继续）"<<endl;
    player->SetLoveStage(1);
    player->AddMentalLevel(2);
    player->AddCharmLevel(2);
  }
  else
  {
    cout<<"女孩露出那种不想伤害人的笑容，为难地摇了摇头。看来你还不够资格啊。（按任意键以继续）"<<endl;
    player->AddMentalLevel(-2);
    player->AddCharmLevel(1);
  }
  system("pause");
  return;
  }
  else if(choice==1)
  {
    cout<<"你已经经历过一次了，多余的期冀只会让已然结痂的伤疤泛脓。你转身离开，不多看一眼。（按任意键以继续）"<<endl;
    system("pause");
    return;
  }
}
else if(player->GetLoveStage()==1)
{
  cout<<"此后你们开始频繁见面，她的每一次笑容都让你沉醉，仿佛她真的是你命中注定的那个人。"<<endl;
  cout<<"直到那一天你接她下晚课。道路上行人寥寥，你扭头看见她的侧脸，银光落在她微微翘起的鼻尖上。突然有种冲动擎住了你，你转身靠近她的脸颊......"<<endl;
  int choice=-1;
  cout<<"输入0亲吻,输入1停下"<<endl;
    while(choice!=0&&choice!=1)
  {
    cin>>choice;
  }
  if(choice==0)
  {
  if(player->GetCharmLevel()>=10)
  {
    cout<<"你吻了上去，如同轻吻露水。她没有抗拒，只是迎上前，伸手搂住你的腰间。恍惚中，你仿佛窥见了永恒的存在（按任意键以继续）。（按任意键以继续）"<<endl;
    player->SetLoveStage(3);
    player->AddMentalLevel(2);
    player->AddCharmLevel(2);
  }
  else
  {
    cout<<"她摇了摇头，轻轻把你推开。“我们还没到那一步吧”。她轻轻地说。（按任意键以继续）"<<endl;
    player->AddMentalLevel(-2);
    player->AddCharmLevel(1);
  }
  system("pause");
  return;
  }
  else if(choice==1)
  {
    cout<<"你在中途停下了，或许现在还太早。（按任意键以继续）"<<endl;
    system("pause");
    return;
  }
}
else if(player->GetLoveStage()==2)
{
  cout<<"你们彻底陷入了热恋，走到哪里都缠在一起。但好景不长，你们爆发了争吵，然后是冷战"<<endl;
  int choice=-1;
  
  cout<<"输入0尝试挽回,输入1选择维持现状,输入2选择分手"<<endl;
    while(choice!=0&&choice!=1&&choice!=2)
  {
    cin>>choice;
  }
  if(choice==0)
  {
  if(player->GetCharmLevel()>=12)
  {int r=rand()%10;
  if(r>=4)
    {cout<<"她哭着抱住了你，两颗心再次紧紧相连。（按任意键以继续）"<<endl;
    player->SetLoveStage(3);
    player->AddMentalLevel(2);
    player->AddCharmLevel(2);}
    else
    {
      cout<<"她摇了摇头，轻轻把你推开。“我们——我们不适合，还是分开一段时间吧。”。她轻轻地说。（按任意键以继续）"<<endl;
    player->SetLoveStage(0);
    player->AddMentalLevel(-4);
    player->AddCharmLevel(1);
    }
  }
  else
  {int r=rand()%10;
  if(r>=7)
    {cout<<"她哭着抱住了你，两颗心再次紧紧相连。（按任意键以继续）"<<endl;
    player->SetLoveStage(3);
    player->AddMentalLevel(2);
    player->AddCharmLevel(2);}
    else
    {
      cout<<"她摇了摇头，轻轻把你推开。“我们——我们不适合，还是分开一段时间吧。”。她轻轻地说。（按任意键以继续）"<<endl;
    player->SetLoveStage(0);
    player->AddMentalLevel(-4);
    player->AddCharmLevel(1);
    }
  }
  system("pause");
  return;
  }
  else if(choice==1)
  {
    int r=rand()%10;
  if(r>=5)
    {cout<<"你们僵持着，一切都没有改变。（按任意键以继续）"<<endl;
    player->SetLoveStage(2);}
    else
    {
      cout<<"是她主动找到了你。“我们不适合，还是分开一段时间吧。”。她轻轻地说。（按任意键以继续）"<<endl;
    player->SetLoveStage(0);
    player->AddMentalLevel(-4);
    }
    system("pause");
  return;
  }
  else{
    cout<<"“我们不适合，还是分开一段时间吧。”（按任意键以继续）"<<endl;
    player->SetLoveStage(0);
    player->AddMentalLevel(-4);
    system("pause");
  return;
  }
  return;
}
else if(player->GetLoveStage()==3)
{cout<<"日子一天天过去，你们的感情逐渐升温，但这一切又能持续多久呢？你不禁想到。（按任意键以继续）"<<endl;
    player->AddMentalLevel(2);
    player->AddCharmLevel(2);

int r=rand()%10;
  if(r>=4){
  }
else{
player->SetLoveStage(2);
}
system("pause");
  return;
}
}
void RandomEvent::Affect(Player *player)const{
  int randNum = 100 * (double(rand()) / (RAND_MAX + 1ll));
  cout<<"你遭遇了随机事件，按任意键继续"<<endl;
  system("pause");
  if (randNum < 25) {
    cout<<" 学校组织新生舞会，你表现出众"<<endl;
    player->AddCharmLevel(2);
    player->AddMentalLevel(2);
  } else if (randNum < 50) {
    cout<<" 你在骑车时不小心受伤"<<endl;
    player->AddHealthLevel(-1);
    player->AddMentalLevel(-1);
  } else if (randNum < 75) {
    cout<<"你睡过头错过了点名"<<endl;
    player->AddKnowledgeLevel(-1);
    player->AddMentalLevel(-1);
  }
  else
  {
    cout<<"跑步打卡抽奖你抽中了大礼包"<<endl;
    player->AddHealthLevel(2);
    player->AddMentalLevel(2);
  }
system("pause");
}