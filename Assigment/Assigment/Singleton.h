#pragma once
template<typename T>
class Singleton {
	public:
		static T& GetInstance();
		virtual ~Singleton();

		static T* Instance;
	protected:
		Singleton();
	private:
	
};

template <typename T>
T* Singleton<T>::Instance = 0;

template<typename T>
inline T& Singleton<T>::GetInstance()
{
	if (Instance == 0) {
		Instance = new T();
	}
	return *Instance;
}
template<typename T>
inline Singleton<T>::~Singleton()
{
	delete Instance;
}
template<typename T>
inline Singleton<T>::Singleton()
{
	
}
