#include "vertexformat.h"
#include "wiidefines.h"

renderer::VertexFormat::VertexFormat(uint32_t formatIndex) : mFormatIndex(formatIndex) {}

void renderer::VertexFormat::Bind()
{
    for (const auto& attribute : mAttributes)
    {
        GX_SetVtxDesc(attribute.Attribute, attribute.DataInputType);
        GX_SetVtxAttrFmt(mFormatIndex, attribute.Attribute, attribute.ComponentType, attribute.ComponentSizeType, 0);
    }
}

void renderer::VertexFormat::AddAttribute(const renderer::VertexFormatAttribute& attribute)
{
    mAttributes.emplace_back(attribute);
}
