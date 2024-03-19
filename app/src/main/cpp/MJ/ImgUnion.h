//class CImgUnion �������������ͼ��
//��һ��λͼ�л��ÿ��ͼ�μ���������ģ���λ����Ϣ��ͼ�εı���Ϊ���ڣ�
//ģ���Ӧ�ı���Ϊ���ף���Ӧͼ����Ч��Ϣ�Ĳ���Ϊ���ڡ�����ʱ���Ƚ�ģ��
//��Ŀ��DC�е�ָ��λ����������ٽ�ͼ����ָ��λ�û������

class CImgUnion
{
public:
	CImgUnion(const char* csName,
			 int nNum,				// number of images
			 SDL_Rect*	prectSize);		// each image size
	~CImgUnion();
	void BltImg(SDL_Surface *screen,int nImgCode,int nBltX,int nBltY);

private:
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Surface* pImg;
	int		nImgNum;
	SDL_Rect*	prectImgSize;
};
