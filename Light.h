#pragma once
#include <d3d12.h>
#include <d3dx12.h>
#include <DirectXMath.h>

class Light
{
private: // エイリアス
	// Microsoft::WRL::を省略
	template<class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;
public: // サブクラス
	// 定数バッファ構造体
	struct ConstBufferData 
	{
		XMVECTOR lightv;
		XMFLOAT3 lightcolor;
	};
private: // 静的メンバ変数
	// デバイス
	static ID3D12Device* device;
	
public: // 静的メンバ関数
	/// <summary>
	/// 静的初期化
	/// </summary>
	/// <param name="device">デバイス</param>
	static void StaticInitialize(ID3D12Device* device);

	void Initialize();

	void Update();


	void Draw(ID3D12GraphicsCommandList* cmdList, UINT rootParameterIndex);

	void TransferConstBuffer();

	void SetLightDir(const XMVECTOR& lightdir);
	void SetLightColor(const XMFLOAT3& lightcolor);

	static Light* Create();

private: // メンバ変数
	ComPtr<ID3D12Resource> constBuff;
	XMVECTOR lightdir = { 1,0,0,0 };
	XMFLOAT3 lightcolor = { 1,1,1 };
	bool dirty = false;
};

