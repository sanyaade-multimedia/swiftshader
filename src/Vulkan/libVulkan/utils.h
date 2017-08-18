#ifndef UTILS_H
#define UTILS_H

#include <unordered_map>
#include <string>
#include <Vulkan\vulkan.h>

namespace vulkan
{
#define ALIGNMENT 8

#define DEFINE_HANDLE_CASTS(__type, __VkType)                              \
                                                                           \
   static inline struct __type *                                           \
   __type ## _from_handle(__VkType _handle)                                \
   {                                                                       \
      return (struct __type *) _handle;                                    \
   }                                                                       \
                                                                           \
   static inline __VkType                                                  \
   __type ## _to_handle(struct __type *_obj)                               \
   {                                                                       \
      return (__VkType) _obj;                                              \
   }

#define DEFINE_NONDISP_HANDLE_CASTS(__type, __VkType)                      \
                                                                           \
   static inline struct __type *                                           \
   __type ## _from_handle(__VkType _handle)                                \
   {                                                                       \
      return (struct __type *)(uintptr_t) _handle;                         \
   }                                                                       \
                                                                           \
   static inline __VkType                                                  \
   __type ## _to_handle(struct __type *_obj)                               \
   {                                                                       \
      return (__VkType)(uintptr_t) _obj;                                   \
   }

#define GET_UNTYPED_FROM_HANDLE(__name, __handle) \
    void* __name = (void*)(uintptr_t) __handle;

#define GET_FROM_HANDLE(__type, __name, __handle) \
   struct __type *__name = __type ## _from_handle(__handle)


		DEFINE_HANDLE_CASTS(Instance, VkInstance)
		DEFINE_HANDLE_CASTS(PhysicalDevice, VkPhysicalDevice)
		DEFINE_HANDLE_CASTS(Device, VkDevice)
		DEFINE_HANDLE_CASTS(Queue, VkQueue)
		DEFINE_HANDLE_CASTS(CommandBuffer, VkCommandBuffer)

		DEFINE_NONDISP_HANDLE_CASTS(Sampler, VkSampler)
		DEFINE_NONDISP_HANDLE_CASTS(ShaderModule, VkShaderModule)
		DEFINE_NONDISP_HANDLE_CASTS(Buffer, VkBuffer)
		DEFINE_NONDISP_HANDLE_CASTS(BufferView, VkBufferView)
		DEFINE_NONDISP_HANDLE_CASTS(DeviceMemory, VkDeviceMemory)
		DEFINE_NONDISP_HANDLE_CASTS(Image, VkImage)
		DEFINE_NONDISP_HANDLE_CASTS(RenderPass, VkRenderPass)
		DEFINE_NONDISP_HANDLE_CASTS(ImageView, VkImageView)
		DEFINE_NONDISP_HANDLE_CASTS(PipelineLayout, VkPipelineLayout)
		DEFINE_NONDISP_HANDLE_CASTS(Pipeline, VkPipeline)
		DEFINE_NONDISP_HANDLE_CASTS(Framebuffer, VkFramebuffer)
		DEFINE_NONDISP_HANDLE_CASTS(CommandPool, VkCommandPool)
		DEFINE_NONDISP_HANDLE_CASTS(Fence, VkFence)
		DEFINE_NONDISP_HANDLE_CASTS(Semaphore, VkSemaphore)
}


namespace vkutils
{
	PFN_vkVoidFunction findEntry(const char *name);
	void *Allocate(const VkAllocationCallbacks *pAlloc, size_t size, size_t align, VkSystemAllocationScope scope);
	void *Alloc(const VkAllocationCallbacks *pParent, const VkAllocationCallbacks *pAlloc, size_t size, size_t align, VkSystemAllocationScope scope);
	void Free(VkAllocationCallbacks *pAlloc, void *pData);
	int formatSize(VkFormat format);
}


#endif