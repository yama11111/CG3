#pragma once
#include <d3d12.h>
#include <d3dx12.h>
#include <DirectXMath.h>

class Light
{
private: // �G�C���A�X
	// Microsoft::WRL::���ȗ�
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;
public: // �T�u�N���X
	// �萔�o�b�t�@�\����
	struct ConstBufferData 
	{
		XMVECTOR lightv;
		XMFLOAT3 lightcolor;
	};
private: // �ÓI�����o�ϐ�
	// �f�o�C�X
	static ID3D12Device* device;
	
public: // �ÓI�����o�֐�
	/// <summary>
	/// �ÓI������
	/// </summary>
	/// <param name="device">�f�o�C�X</param>
	static void StaticInitialize(ID3D12Device* device);

	void Initialize();

	void Update();


	void Draw(ID3D12GraphicsCommandList* cmdList, UINT rootParameterIndex);

	void TransferConstBuffer();

	void SetLightDir(const XMVECTOR& lightdir);
	void SetLightColor(const XMFLOAT3& lightcolor);

	static Light* Create();

private: // �����o�ϐ�
	ComPtr<ID3D12Resource> constBuff;
	XMVECTOR lightdir = { 1,0,0,0 };
	XMFLOAT3 lightcolor = { 1,1,1 };
	bool dirty = false;
};

