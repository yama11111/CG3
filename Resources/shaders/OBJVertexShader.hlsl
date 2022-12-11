#include "OBJShaderHeader.hlsli"

VSOutput main(float4 pos : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD)
{
	// 右下奥　向きのライト
	float3 lightdir = float3(1, -1, 1);
	lightdir = normalize(lightdir);
	// ライト色
	float3 lightcolor = float3(1, 1, 1);
	// ピクセルシェーダーに渡す値
	VSOutput output;
	output.svpos = mul(mat, pos);
	// Lambert
	output.color.rgb = dot(-lightdir, normal) * m_diffuse * lightcolor;
	output.color.a = m_alpha;
	output.uv = uv;

	return output;
}